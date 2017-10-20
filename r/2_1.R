snee = readLines("http://www.biostatisticien.eu/springeR/snee74en.txt");
writeLines(snee, "snee.txt")
snee_table = read.table("snee.txt", sep = " ", header = T)

snee_row = nrow(snee_table)
snee_col = ncol(snee_table)

snee_tables = sapply(snee_table, function(x) table(x))
barplot(snee_tables$hair)
barplot(snee_tables$eyes)
barplot(snee_tables$gender)

eyes_hair_table = with(snee_table, table(eyes, hair))

prop.table(eyes_hair_table, 1);
prop.table(eyes_hair_table, 2);

library(gmodels)
CrossTable(snee_table$hair, snee_table$eyes)


# 期望频数表
# 某点(i, j)期望频数 = sum(i, ) * sum(, j) / total 
expected_num = matrix(rep(margin.table(eyes_hair_table, 1), times = 4), nrow = 4, ncol = 4) *
  matrix(rep(margin.table(eyes_hair_table, 2), each = 4), nrow = 4, ncol = 4) / sum(eyes_hair_table);

colnames(expected_nums) = colnames(eyes_hair_table)
rownames(expected_nums) = rownames(eyes_hair_table)

#区别

(expected_nums - eyes_hair_table) ^ 2

#卡方检验
chisq.test(eyes_hair_table)