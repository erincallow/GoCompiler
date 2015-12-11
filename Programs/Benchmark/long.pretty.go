package main
func fact(n int)int{
	if n==1{
	return 1

}else {
	return n*fact(n-1)

}

}

func main()int{
	var a int=1;

	var i int=0;

	for a<2000000000{
	i = fact(5)
	a+=1

}
	print(i)
	return 0

}

