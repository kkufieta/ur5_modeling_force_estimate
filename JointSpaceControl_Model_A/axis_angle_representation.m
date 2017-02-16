function R = axis_angle_representation(k, theta)

kx = k(1);
ky = k(2);
kz = k(3);

v = 1-cos(theta);
s = sin(theta);
c = cos (theta);

r11 = kx^2*v + c;
r12 = kx*ky*v - kz*s;
r13 = kx*kz*v+ky*s;
r21 = kx*ky*v+kz*s;
r22 = ky^2*v + c;
r23 = ky*kz*v-kx*s;
r31 = kx*kz*v-ky*s;
r32 = ky*kz*v + kx*s;
r33 = kz^2*v+c;

R = [r11, r12, r13; r21, r22, r23; r31, r32, r33];