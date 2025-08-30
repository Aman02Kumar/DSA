select score ,
    dense_rank() over (order by score DESC) as `rank`
From Scores