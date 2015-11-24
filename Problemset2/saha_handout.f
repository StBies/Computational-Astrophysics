      module eos
      implicit none
      include 'physconst.inc'
c
      integer, parameter:: maxel=2
      integer, parameter:: maxion=maxel
c
      integer :: code(maxel)=(/ 100, 200 /) ! element codes
      real*8 :: eps(maxel)=(/ 1.d0, 0.d0 /) ! element abundance
      real*8 :: partial_pressures(0:maxion,maxel)
c
      real*8 :: ion_fraction(0:maxion)
      real*8, private :: T,Pgas,Pe,n_tot
c
      contains
c
      subroutine zusum(T,Pgas,code,q,chi)
c     -----------------------------------
      implicit none
      real*8, intent(in) :: T,Pgas
      integer, intent(in) :: code
      real*8, intent(out) :: q(0:maxion)
      real*8, intent(out) :: chi(0:maxion)
c
***********************************************************************
* calculate partition function Q and ionization energies chi for
* (T,Pg) and element code (100*z)
***********************************************************************

      q(:) = 0
      chi(:) = 0
      select case(code)
       case(100)
        q(0) = 2.d0
        q(1) = 1.d0
        chi(0) = 13.595d0*ev2erg
       case(200)
        q(0) = 1.d0
        q(1) = 2.d0
        q(2) = 1.d0
        chi(0) = 24.580d0*ev2erg
        chi(1) = 54.403d0*ev2erg
      case default
       write(*,*) 'zusum: code error:',code
       stop 'zusum error'
      end select
      return

      end subroutine zusum



      double precision function Saha(T,Ne)
c     -----------------------------------------
      implicit none
      real*8, intent(in) :: T,Ne

***********************************************************************
* calculate Saha factor for H II -> H I
***********************************************************************
c--
c-- local variables:
c--
      real*8 :: q(0:maxion)
      real*8 :: chi(0:maxion)
      real*8 sum,smax,ktinv,tpeup
c--
c-- some useful constants:
c--
      real*8 :: sconst

      integer i

      save

      sconst = 1.d0/(sqrt(2.d0*pi*me*kb)/h)**3
      ktinv = 1.d0/(kb*T)
c--
c-- H only (code = 100)
c--
c--
c-- compute Q's and load ionization energies
c--
      call zusum(T,Pgas,100,q,chi)
c--
c-- compute saha factor (H only):
c--
      saha = sconst*q(0)/(q(1)*2.d0*t**1.5d0)*exp(chi(0)*ktinv)

      return

      end function saha



      subroutine eos_ions(t_in,pg_in,pe_out,itused)
c     ---------------------------------------------
      implicit none
      real*8, intent(in) :: t_in,pg_in
      real*8, intent(inout) :: pe_out
      integer, intent(out) :: itused
************************************************************************
* solution of the EOS for ions and atoms using Brent's method
*
*-- input:
* t_in: temperature (k)
* pg_in: gas pressure (dyn/cm**2)
* pe_out: electron pressure (dyn/cm**2)
* mode: slot to store the results into
*-- output:
* pe: electron pressure (dyn/cm**2)
* itused: number of iterations used
*
************************************************************************
c
      real*8 nemin,nemax,ngold,hlp,S_H,n_H,n_HI,n_HII,ne
      integer i,j
c--
c-- init's:
c--
      t = t_in
      pgas = pg_in
      n_tot = pgas/(kb*T)
c--
c-- get inital guesses for Pe:
c--
      nemin = (1d-10*n_tot)
      nemax = (0.70*n_tot)
c--
c-- check if the interval works, correct if not
c--
c--
c-- use a solver to solve for ne:
c--
      ne = 0
      call rootfinder(ne,nemin,nemax,t,itused)
      pe = ne*kb*T
c--
c-- distribute the results to target array:
c--
      partial_pressures(:,:) = 0
      i = 1
c--
c-- compute Saha factor:
c--
      S_H = Saha(T,ne)
c--
c-- free H nuclei:
c--
      n_H = N_tot-ne
c--
c-- number density of H II:
c--
      n_HII = n_H/(1.d0+ne*S_H)
c--
c-- number density of H I:
c--
      n_HI = n_H/(1.d0+1.d0/(ne*S_H))
c--
c-- transfer to output array:
c--
      partial_pressures(0,1) = n_HI*kb*T
      partial_pressures(1,1) = n_HII*kb*T
      pe_out = pe

      return
      end subroutine eos_ions

c--
c Rootfinding-function
c--
      subroutine rootfinder(ne,nemax,nemin,t,itused)
c     ----------------------------------------------
      implicit none

      real*8, intent(out) :: ne
      real*8, intent(inout) :: nemax,nemin,t
      integer, intent(out) :: itused

      real*8 :: middle

      write (*,*) 'Die Fortran, die!'

c     Check if interval contains the root:
      do while (f(nemin) * f(nemax) >= 0)
	nemin = nemin - 0.1 * nemin
	nemax = nemax + 0.1 * nemax
      end do

      write (*,*) 'Intervall ist ok'

      itused = 0
      middle = (nemax + nemin) / 2.d0

      do while (abs(nemax - nemin) > 0.005 * nemax)
	if (f(nemin) * f(middle) < 0) then
		nemax = middle
		middle = (nemin + middle) / 2
	else if(f(middle) * f(nemax) < 0) then
		nemin = middle
		middle = (middle + nemax) / 2
        end if
        itused = itused + 1		
      end do
      ne = nemax
      
      return
      end subroutine rootfinder
c----------------END SUBROUTINE-----------------------------------

c--
c Nonlinear function from lecture notes
c--
      double precision function F(n_e)
c     -------------------------------
      implicit none

      real*8 :: n_e

      F = ((n_tot - n_e) / (1.d0 + n_e * saha(T,n_e)) - n_e)
      end function F
c---------------END FUNCTION--------------------------------------


      end module eos



      program eos_table
      use eos
      implicit none

      real*8 T,Pgas,Pe,qfak
      real*8 Pea,PH1,PH2
      integer :: i,itused

      real*8 :: q(0:maxion),chi(0:maxion)

      code(1) = 100 ! H
      code(2) = 200 ! He

      eps(1) = 1.d0 ! eps(H)
      eps(2) = 0.d0 ! eps(He)

      eps(:) = eps(:)/sum(eps(:)) ! re-normalize
c
      T = 5000.d0
      Pgas = 100.d0
      Pe = Pgas*0.5d0
c--
c-- test the real thing:
c--
  300 continue
      write(*,*) 'Fortran ist leider scheisse!'
      write(*,*) 'enter T,Pgas:'
      read(*,*) T,Pgas
      call eos_ions(t,pgas,pe,itused)
      write(*,*) 'results for (T,pgas):',T,Pgas
      write(*,*) 'Pe=',Pe
      write(*,*) 'iterations:',itused
      write(*,*) 'partial pressures'
      do i=1,1
       write(*,*) 'code=',code(i)
       write(*,*) partial_pressures(0:code(i)/100,i)
      enddo
c--
c-- compare to analytic solution for Pe:
c--
      call analytic(T,Pgas,Pea,PH1,PH2)
      write(*,*) "analytic Pe =",Pea," error=",(Pe-Pea)/Pe
      write(*,*) "analytic PH1=",PH1," error=",
     &           (partial_pressures(0,1)-PH1)/PH1
      write(*,*) "analytic PH2=",PH2," error=",
     &           (partial_pressures(1,1)-PH2)/PH2
      goto 300

      contains


      subroutine analytic(T,Pg,Pe,PH1,PH2)
      implicit none
      real*8 :: T,Pg,Pe,PH1,PH2

      include 'physconst.inc'
      real*8 ::N,Ne,phi,q1,q2,chi

      N = Pg/(kb*T)

      q1 = 2.d0
      q2 = 1.d0
      chi = 13.595d0*ev2erg
      phi = 2.d0*q2/q1*(2.d0*pi*me*kb*T/h**2)**1.5d0*exp(-chi/(kb*T))

      Ne = phi*(sqrt(1.d0+N/phi)-1.d0)

      Pe = Ne*kb*T
      PH2 = Pe
      PH1 = Pg-2.d0*Pe

      return
      end subroutine analytic
      end
