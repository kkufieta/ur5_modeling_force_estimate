function X = FK(q)
global a3;

q1 = q(1);
q2 = q(2);
q3 = q(3);
q4 = q(4);
q5 = q(5);
q6 = q(6);

X = [a3 * cos(q1 + q3) + sin(q1) * q2;
     a3 * sin(q1 + q3) - cos(q1) * q2;
     0;
     0;
     0;
     0];
end