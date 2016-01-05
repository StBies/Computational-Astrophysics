set terminal png size 720,640
set output './plots/random.png'
set xlabel 'x'
set ylabel 'y'
set zlabel 'z'
set title 'Correlations between ANSI C random numbers'
set grid
set xrange [0:1]
set yrange [0:1]
set zrange [0:1]
splot './ANSI_random.txt' using 1:2:3 title 'random numbers'
set output
set terminal png size 720,640
set output './plots/convergence.png'
set xlabel 'Number of draws'
set ylabel 'Integral [a.u.]'
set title 'Convergence of the MC integral'
set grid
set autoscale
plot './convergenceSimple.dat' using 1:2 title 'convergence',pi/4 t 'Pi/4'
set output

