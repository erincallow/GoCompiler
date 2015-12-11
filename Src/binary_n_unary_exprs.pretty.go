package main
func main(){
	a:= 8
	b:= 2.000000
	c:= "lah"
	d:= 'a'
	e:= true
	println(e||e, e&&!e, c=="a", a<2, b>=3.000000, c>"la", d>='b', "a"+"b", a-2, 2*3, 2%5, 2|2, 3&a, 1<<2, 3<<2, 2&^a, a^a)
	println(+2, +2.000000, +'x')
	println(-2, -2.000000, -'x')
	println(^2, ^'x')
	println(!true, !false)

}

