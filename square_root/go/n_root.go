package main

import (
	"flag"
	"fmt"
)

func main() {
	var value float64
	var n int
	valueFlagPtr := flag.Float64("value", 100, "number for which n root has to be solved")
	nFlagPtr := flag.Int("n", 2, "(n) power for which n root has to be solved")
	flag.Parse()
	value = *valueFlagPtr
	n = *nFlagPtr

	optimization := Optimization{}
	optimization.SetDefaults()
	optimization.InitialDivision = true
	optimization.Average = true
	root, iteration := nRoot(value, n, optimization)
	fmt.Printf("Value:%v\nn:%v\nRoot: %v\nNumber of Iterations: %v\n", value, n, root, iteration)
}
