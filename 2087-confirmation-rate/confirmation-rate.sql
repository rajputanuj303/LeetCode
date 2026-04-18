Select Signups.user_id , Round(ifnull(sum(Confirmations.action='confirmed')/count(Signups.user_id),0),2) as confirmation_rate 
from Signups
left join Confirmations
on Signups.user_id=Confirmations.user_id
group by Signups.user_id