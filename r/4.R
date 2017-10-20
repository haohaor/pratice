# problem5

num = 11 : 20

prim = c(2, 3, 5, 7, 11, 13, 17, 19)

cnt = rep(0, length(prim))

for (i in 1 : length(num)) {
  for (j in 1 : length(prim)) {
    if (num[i] %% prim[j] == 0) {
      c = 0;
      while (num[i] > 1 && num[i] %% prim[j] == 0) {
        c = c + 1
        num[i] = num[i] / prim[j]
      }
      cnt[j] = max(cnt[j], c);
    }
  }
}

for (i in 1 : length(prim)) {
  prim[i] = prim[i] ^ cnt[i];
}

prod(prim)
