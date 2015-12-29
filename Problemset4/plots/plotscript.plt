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
splot './randomnumbers.txt' using 1:2:3 title 'random numbers'
set output
set terminal wxt
replot
pause -1

