#gnuplot-script that generates a histogram of the data
set terminal png size 960,720
set output 'nonOpt.png'
set title 'Runtime for problem one'
set xlabel 'Runtime (ms)'
set ylabel 'Frequency'
n=100 #number of intervals
max=1. #max value
min=0. #min value
width=(max-min)/n #interval width
#function used to map a value to the intervals
hist(x,width)=width*floor(x/width)+width/2.0
set boxwidth width*0.9

#count and plot
plot "nonOpt.dat" u (hist($2,width)):(1.0) smooth freq w boxes lc rgb"green" notitle
set output
