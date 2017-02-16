function dJ_dq    = Derivative_Jacobian(q_qd)
% GEOMETRICAL_JACOBIAN - Jacobian from Base to Tool.
%  Calculates the geometrical Jacobian.
q = q_qd(1:6);
qd = q_qd(7:12);
UR5 = Create_Serial_Link();
dJ_dq = UR5.jacob_dot(q, qd);

end

