#gnuplot-script that generates a histogram of the data
set terminal png size 960,720
set output './plots/nonOpt.png'
set title 'Runtime for problem one without optimization'
set xlabel 'Runtime (ms)'
set ylabel 'Frequency'
n=100 #number of intervals
max=1. #max value
min=0. #min value
width=(max-min)/n #interval width
#function used to map a value to the intervals
hist(x,width)=width*floor(x/width)+width/2.0
set boxwidth width*0.9

#count and plot[0:1]
plot[0:1] "nonOpt.dat" u (hist($1,width)):(1.0) smooth freq w boxes lc rgb"green" notitle
set output

set terminal png size 960,720
set output './plots/opt3.png'
set title 'Runtime for problem one with vectoroptimization (O3)'
set xlabel 'Runtime (ms)'
set ylabel 'Frequency'
n=100 #number of intervals
max=1. #max value
min=0. #min value
width=(max-min)/n #interval width
#function used to map a value to the intervals
hist(x,width)=width*floor(x/width)+width/2.0
set boxwidth width*0.9

#count and plot[0:1]
plot[0:1] "opt3.dat" u (hist($1,width)):(1.0) smooth freq w boxes lc rgb"green" notitle
set output

set terminal png size 960,720
set output './plots/nonOptPar.png'
set title 'Runtime for problem one without vectoroptimization with openMP'
set xlabel 'Runtime (ms)'
set ylabel 'Frequency'
n=100 #number of intervals
max=1. #max value
min=0. #min value
width=(max-min)/n #interval width
#function used to map a value to the intervals
hist(x,width)=width*floor(x/width)+width/2.0
set boxwidth width*0.9

#count and plot[0:1]
plot[0:1] "nonOptPar.dat" u (hist($1,width)):(1.0) smooth freq w boxes lc rgb"green" notitle
set output

set terminal png size 960,720
set output './plots/opt3par.png'
set title 'Runtime for problem one wit vectoroptimization (O3) and openMP'
set xlabel 'Runtime (ms)'
set ylabel 'Frequency'
n=100 #number of intervals
max=1. #max value
min=0. #min value
width=(max-min)/n #interval width
#function used to map a value to the intervals
hist(x,width)=width*floor(x/width)+width/2.0
set boxwidth width*0.9

#count and plot[0:1]
plot[0:1] "opt3par.dat" u (hist($1,width)):(1.0) smooth freq w boxes lc rgb"green" notitle
set output
