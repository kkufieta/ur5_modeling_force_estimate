for (i=1:length(q_actual.time)-1)
    time_diff_q_actual(i) = q_actual.time(i+1)-q_actual.time(i);
end

for (i=1:length(qd_actual.time)-1)
    time_diff_qd_actual(i) = qd_actual.time(i+1)-qd_actual.time(i);
end

for (i=1:length(q_target.time)-1)
    time_diff_q_target(i) = q_target.time(i+1)-q_target.time(i);
end

for (i=1:length(qd_target.time)-1)
    time_diff_qd_target(i) = qd_target.time(i+1)-qd_target.time(i);
end


length(time_diff_q_actual)
length(time_diff_qd_actual)
length(time_diff_q_target)
length(time_diff_qd_target)

time_diff = [time_diff_q_actual', time_diff_qd_actual', ...
             time_diff_q_target', time_diff_qd_target']