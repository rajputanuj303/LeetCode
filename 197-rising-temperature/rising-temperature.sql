SELECT  w1.id FROM
Weather as w1 JOIN Weather  as w2 on DateDiff( w1.recordDate,w2.recordDate)=1 where w1.temperature> w2.temperature ;