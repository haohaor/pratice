# 假设未成年兔子经过1个月长成成年兔子

rb <- function(m) {
  adult = c(1)
  minor = c(1)
  i = 2;
  while (i <= m) {
    adult[i] = adult[i-1] + minor[i-1]
    minor[i] = adult[i-1] * 3
    i = i + 1
  }
  adult[m] + minor[m]
}

rb(5)
