function aq = InvDyn_Control(u)

global Kp;
global Kd;
global UR5;
%----------------------------desired trajectory---------------------------%
xd = u(1:3);
dxd = u(4:6);
ddxd = u(7:9);
%-------------------------------------------------------------------------%
q = u(10:12);
dq = u(13:15);
%-------------------------------------------------------------------------%

x = FK(q);
x = [x(1);x(2);q(1)+q(3)];
dx = Ja(q)*dq;

ax = ddxd + (Kd*(dxd - dx) + Kp*(xd - x));

aq = Ja(q,UR5)\(ax - dJa_dq(q,dq,UR5));

end