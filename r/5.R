library(ISLR)
data(Wage)
wage_mean = with(Wage, mean(wage))
wage_sd = with(Wage, sd(wage))
with(Wage,quantile(wage,0.25))
with(Wage,quantile(wage,0.75))
#age和wage的相关性
with(Wage, cor(wage, age))
with(Wage, cov(wage, age))

#交互频数表
table(Wage$education)
health.table <- with(Wage,table(health,health_ins))
health.m <- as.matrix(health.table)
apply(health.m, 2, function(x) x/sum(x))
margin.table(health.table, 1)
prop.table(health.table, 1)
plot(health.table)
with(Wage, table(health, health_ins, jobclass))
with(Wage, xtabs(~health + health_ins + jobclass))
with(Wage, ftable(health ~ health_ins + jobclass))

#计算不同education的wage均值以及相应人数

library(plyr)
ddply(Wage, .(education), function(x) each(mean,length)(x$wage))

