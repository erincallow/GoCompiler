package main
type point struct {
x, y, z float64
}

type indirect_point point
var y indirect_point;

type vector struct {
i indirect_point
j indirect_point
}

func main(){
	var s struct {
a bool
b int
c string
};

	s.a = true
	s.b = 42
	s.c = "struct"
	var p point;

	p.x = 0.000000
	p.y = -1.000000
	p.z = 1.000000
	var q indirect_point;

	q.x = 0.000000
	q.y = -1.000000
	q.z = 1.000000
	var v vector;

	v.i = q
	v.j = q
	v.i.x = 2.000000
	v.i.y = 3.000000
	v.i.z = 4.000000

}

