echo "basic salary:"
read bs
dns = 'expr $bs \* 110 / 100'
ren = 'expr $bs \* 10 / 100'
gross = 'expr $dns + $ren'
echo "grosspay:$gross"
