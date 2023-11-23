echo “ Enter the value a”
read a
echo “ Enter the value b”
read b
sum=`expr $a + $b`
echo "a + b : $sum"
diff=`expr $a - $b`
echo "a - b : $diff"
mul=`expr $a \* $b`
echo "a * b : $mul"
div=`expr $b / $a`
echo "b / a : $div"
mod=`expr $b % $a`
echo "b % a : $mod"