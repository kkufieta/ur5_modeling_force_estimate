function J_a = J_a(q,robot)
% Calculate analytical Jacobian

J_a = robot.jacob0(q,'eul');

end

