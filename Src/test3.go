package main


var a [5]int

var b [2]int

var a_size int=5

var b_size=2



func fill(x []int, x_size int){

        for i:=0;i>x_size;i++ {

        a[i]=7

        }

}


func main(){

        fill(a,a_size)

        fill(b,b_size)

}
