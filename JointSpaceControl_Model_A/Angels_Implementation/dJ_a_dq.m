function dJ_a_dq = dJ_a_dq(q,dq,robot)
% Calculate analytical Jacobian

dJ_a_dq = robot.jacob_dot(q,dq);

end

