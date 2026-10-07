set terminal pdfcairo font "Helvetica,12" size 5in,3in
set output "out.pdf"

set xlabel "Number of inputs"
set ylabel "Number of Comparisons"

plot "output.txt" using 1:2 with lines title "Bubble Sort", \
     "output.txt" using 1:4 with lines title "Merge Sort"

set ylabel "Computation Time"

plot "output.txt" using 1:3 with lines title "Bubble Sort", \
     "output.txt" using 1:5 with lines title "Merge Sort"

set output