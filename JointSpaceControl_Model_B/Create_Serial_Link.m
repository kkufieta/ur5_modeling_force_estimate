function UR5     = Create_Serial_Link()
% ANALYTICAL JACOBIAN - Jacobian from Base to Tool.
%  Calculates the analytical Jacobian, based on the Euler angle transform
%  representation.

qn = zeros(1,6);
dh = DenavitHartenberg(qn);
UR5 = SerialLink(dh); % dh = [theta, d, a, alpha]

end

