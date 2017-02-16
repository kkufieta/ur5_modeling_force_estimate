function J_a   = Analytical_Jacobian(q)
% ANALYTICAL JACOBIAN - Jacobian from Base to Tool.
%  Calculates the analytical Jacobian, based on the Euler angle transform
%  representation.
UR5 = Create_Serial_Link();
J_a = UR5.jacob0(q,'eul');

end

