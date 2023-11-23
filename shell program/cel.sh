echo -n  "Enter fahrenheit"
read p
c=`(expr "($p - 32) * 5 / 9")`
echo "Celsius is : $c"
