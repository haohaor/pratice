function compare(Old, New) {
  const record = new Map();
  // record every ele's pre group Id
  for (let i = 0; i < Old.length; ++ i) {
    for (let j = 0; j < Old[i].length; ++ j) {
      record.set(Old[i][j], i);
    }
  }
  const proportionInNewGroup = [];
  for (let i = 0; i < Old.length; ++ i) {
    proportionInNewGroup.push([]);
    for (let j = 0; j < Old.length; ++ j)
      proportionInNewGroup[i].push(0);
  }
  for (let i = 0; i < New.length; ++ i) {
    for (let j = 0; j < New[i].length; ++ j) {
      const preGroup = record.get(New[i][j]);
      proportionInNewGroup[preGroup][i] ++;
    }
  }
  const vis = new Map(),
      reflect = [];
  let sum = 0;
  for (let i = 0; i < proportionInNewGroup.length; ++ i) {
    let maxV = -1, maxP = -1;
    for (let j = 0; j < proportionInNewGroup[i].length; ++ j) {
      if (vis.has(j)) continue;
      if (maxV < proportionInNewGroup[i][j]) {
        maxV = proportionInNewGroup[i][j];
        maxP = j;
      } else if (maxV == proportionInNewGroup[i][j]) {
        let p0 = maxV / New[j].length,
            p1 = maxV / New[maxP].length;
        if (p0 - p1 > 0) {
          maxV = proportionInNewGroup[i][j];
          maxP = j;
        }
      }
    }
    reflect[i] = maxP;
    sum += Old[i].length - maxV;
    vis.set(maxP, true);
  }
  console.log(reflect);
  return sum;
}

A = [[1,2,3],[4,5],[6,7]]
B = [[4,6,7],[1,2,3],[5]]
compare(A, B)
