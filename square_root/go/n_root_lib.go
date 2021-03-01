package main

import "math"

// Optimization optimization options
type Optimization struct {
	InitialDivision bool
	Average         bool
	AverageForce    bool // Overwrite Average flag, average the old root result and current root result
}

// SetDefaults set the Optimization object defaults
func (o *Optimization) SetDefaults() {
	o.InitialDivision = false
	o.Average = false
	o.AverageForce = false
}

func nRoot(number float64, n int, optimization Optimization) (float64, int) {
	var root float64
	var rootLastResult float64
	var iteration int
	isNNegative := false
	if n < 0 {
		isNNegative = true
		n = -n
	}
	rootResult := func() (float64, int) {
		if isNNegative {
			return 1 / root, iteration
		}
		return root, iteration
	}

	if number == 0 {
		return 0, 0
	}
	root = number
	if n == 1 {
		return rootResult()
	}
	if optimization.InitialDivision {
		divisionIncrement := 0
		if n > 2 {
			divisionIncrement = n - 2
		}
		root = number / float64(4+divisionIncrement)
	}

	if power(root, n) == number {
		rootResult()
	}
	for {
		iteration++
		secondLastRootResult := rootLastResult // required for oscillating results
		rootLastResult = root

		// Core formula
		root = ((number / power(root, n-1)) + root) / 2
		powerFinal := power(root, n)

		// check if root is final
		if rootLastResult == root || powerFinal == number {
			break
		}

		// required for oscillating results
		if secondLastRootResult == root {
			if powerFinal > number {
				root = rootLastResult
			}
			break
		}

		// reduce the number of iterations by making the root value closer to original value
		if (optimization.Average && powerFinal < number) || optimization.AverageForce {
			root = (rootLastResult + root) / 2
		}
	}

	// course corrections for situations when result got fixated due to number precision
	// example: 1000000 with n = 6
	if power(root, n) != number {
		if power(math.Ceil(root), n) == number {
			root = math.Ceil(root)
		} else if power(math.Floor(root), n) == number {
			root = math.Floor(root)
		}
	}
	return rootResult()
}

func power(value float64, n int) float64 {
	if n == 1 {
		return value
	}
	if n == 0 {
		return 1
	}
	if n%2 == 0 {
		temp := power(value, n/2)
		return temp * temp
	}
	return power(value, n-1) * value
}
