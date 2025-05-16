read -p "Enter n:" input 
f0=0
f1=1

for (( i = 0 ; i<=input ; i++))
do
	if [ "$i" -eq  0 ]; then 
	echo  0 
	 

	elif [ "$i" -eq 1 ];then 
	echo 1
	 
	else 
	temp=$f1
	f1=$((f0+f1))
	echo $f1
	f0=$temp
	
	fi



done



