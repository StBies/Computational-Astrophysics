set terminal epslatex color
set output 'plots/plot_low.tex'
set xlabel 'T (K)'
set xtics 2e5
set ylabel '$p_{e}$ dyn cm$^{-2}$'
set grid
set title 'Pure Hydrogen'
plot 'data.dat' using 1:2 title '$P_{\textnormal{gas}}=10^{-4}$ dyn cm$^{-2}$'
set output
set output 'plots/plot_mid.tex'
plot 'data.dat' using 1:3 title '$P_{\textnormal{gas}} = 10^{6}$ dyn cm$^{-2}$'
set output
set output 'plots/plot_high.tex'
plot 'data.dat' using 1:4 title '$P_{\textnormal{gas}} = 10^{12}$ dyn cm$^{-2}$'
set output


