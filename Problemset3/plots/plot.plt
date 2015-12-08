set terminal png size 720,680
set output './plots/orbits.png'
set title 'Planetary orbits (simulated two years)'
set xlabel 'x [astronomical units]'
set ylabel 'y [astronomical units]'
set grid
plot './plots/planet.dat' using 1:2 title 'Earth', './plots/planet.dat' using 3:4 title 'Jupiter'
set output
set title 'Energy of Earth'
set output './plots/energy.png'
set xlabel 't [yr]'
set ylabel 'E [MJ]'
plot './plots/planet.dat' using 5:6 title 'Earth'
set output

