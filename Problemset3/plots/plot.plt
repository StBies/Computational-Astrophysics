set terminal png size 720,680
set output './plots/orbits.png'
set title 'Planetary orbits'
set xlabel 'x [astronomical units]'
set ylabel 'y [astronomical units]'
set grid
plot './plots/planet.dat' using 1:2 title 'Earth', './plots/planet.dat' using 3:4 title 'Jupiter'
set output
set title 'Energy of Earth'
set output './plots/energyEarth.png'
set xlabel 't [yr]'
set ylabel 'E [MJ]'
plot './plots/planet.dat' using 5:6 title 'Energy'
set output
set title 'Energy of Jupiter'
set output './plots/energyJupiter.png'
set xlabel 't [yr]'
set ylabel 'E [MJ]'
plot './plots/planet.dat' using 5:7 title 'Jupiter'
set output
set title 'Angular Momentum of Earth'
set output './plots/angularEarth.png'
set xlabel 't [yr]'
set ylabel 'L [kg * km**2 / s]'
plot './plots/planet.dat' using 5:8 title 'Earth'
set output
set title 'Angular Momentum of Jupiter'
set output './plots/angularJupiter.png'
set xlabel 't [yr]'
set ylabel 'L [kg * km**2 / s]'
plot './plots/planet.dat' using 5:9 title 'Jupiter'
set output
