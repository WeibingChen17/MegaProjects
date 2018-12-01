# Calculat Pi up to N digit after decimal
## Use GMP 
The basic idea is to use GMP and an iterative algorithm:
$$
y_0 = \sqrt{2} - 1; a_0 = 6 - 4\sqrt{2}
f(y) = (1-y^4)^{1/4}
y_{k+1} = (1 -f(y_k)) / (1 + f(y_k)) ; a_{k+1} = a_k(1 + y_{k+1})^4 - 2^{2k+3}y_{k+1}(1 + y_{k+1} + y_{k+1}^2)
$$
It works.  However, it is very bad to control the precision: we don't how many precision of $y$ and $a$ is enough to calculate a $\pi$ of $n$ precisin. All the numbers (1, 4, 6, $\sqrt{2}$) also need to have very high precision, which means not very efficient. 

