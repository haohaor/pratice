fib <- function(n) {
  i = 2
  x = 1 : 2
  while (x[i] < n) {
    x[i+1] = x[i-1] + x[i];
    i = i + 1;
  }
  x[-i]
}

# get all numbers less than 4000000
n = fib(4000000-1)
sum(n[n %% 2 == 0])
