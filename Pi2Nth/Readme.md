# Calculate Pi up to N digit after decimal
## Use GMP and Borwein's algorithm
The basic idea is to use GMP and an iterative algorithm:

$$
y_0 = \sqrt{2} - 1; a_0 = 6 - 4\sqrt{2};

f(y) = (1-y^4)^{1/4};

y_{k+1} = (1 -f(y_k)) / (1 + f(y_k)) ; a_{k+1} = a_k(1 + y_{k+1})^4 - 2^{2k+3}y_{k+1}(1 + y_{k+1} + y_{k+1}^2)
$$

Note: to get the $\Pi$ of $m$ precision, we need to set the precision of all the numbers to be of the same precision at the beginning. That is, it is not a self-correcting algorithm. So we need to calculate from beginning for each input.

## Todo
* Caching the calcuated pi for frequent inquiry.
* Keep a (time) limit to how far the program will go.
