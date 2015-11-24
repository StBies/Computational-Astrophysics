set terminal epslatex color
set output 'plot.eps'
set xlabel 'T (K)'
set ylabel '$n_{e}$'
set grid
set title 'fail'
plot 'data.dat' using 1:2 title '$P_{\textnormal{gas}}=10^{-6}$ EINHEITEN!!!!'
plot 'data.dat' using 1:3 title '$P_{gas} = ....$'
plot 'data.dat' using 1:4 title '$P_{gas} = ...$'
set output
