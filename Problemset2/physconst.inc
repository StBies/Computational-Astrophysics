c
c-- physical parameters:
       real*8 h
       real*8 ev2erg
       real*8 c
       real*8 e
       real*8 wlyman
       real*8 abohr
       real*8 whe2lyman
       real*8 pi
       real*8 pi2
       real*8 pi4
       real*8 a2cm
       real*8 c1
       real*8 stefco
       real*8 clight
       real*8 boltz
       real*8 gravconst
       real*8 rg
       real*8 year
       real*8 hsun
       real*8 rydberg
      real*8 kb,km2cm,me,mh,kev,msun,mspyr
      parameter(h=6.62619d-27,kb=1.380622d-16,kev=8.617385d-5)
      parameter(me=9.109556d-28)
      parameter(ev2erg=1.602d-12,c=2.997924562d+10,e=4.80325d-10)
      parameter(wlyman=911.7535d+0,mh=1.67333d-24,abohr=0.52917722d-8)
      parameter(whe2lyman=227.88486d0)
      parameter(pi=3.14159265359d0,pi2=2.d0*pi,pi4=4.d0*pi)
      parameter(km2cm=1d+05,a2cm=1d-08)
      parameter(c1=h*c/ev2erg)
      parameter(rydberg=1.0973731534d5)

c--
c-- mathematical and physical constants
c--------------------------------------
c--
      parameter(stefco=5.66961d-05,clight=2.997924562d+10)
      parameter(boltz=1.380622d-16,gravconst=6.6732d-8)
      parameter(rg=8.31434d+07,year=31556925.9747d0)
      parameter(hsun=3.826d33/(pi4*pi4),msun=1.989d33,mspyr=msun/year)
