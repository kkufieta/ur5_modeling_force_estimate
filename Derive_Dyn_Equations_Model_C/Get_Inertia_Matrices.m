function [I_1, I_2, I_3, I_4, I_5, I_6] = Get_Inertia_Matrices()

%% Calculate and return the Inertia Matrices around approximated MCP
% MCP are approximated but equal or almost equal to the MCP that are
% provided by the UR5 manufacturer

syms h r m do_x do_y do_z;

%% Information about all elementary cylinders: Mass, Radius, Height
% Information about distance from common mass center point to local mass
% center point
% All values given in [m] and [kg]


% LINK 1 -> Two elementary cylinder
h_1_1 = 54.19       * 0.001;
r_1_1 = 58.9        * 0.001;
do_1_1_x = 0        * 0.001;
do_1_1_y = -12.29   * 0.001;
do_1_1_z = 0        * 0.001;

h_1_2 = 75.81       * 0.001;
r_1_2 = 58.9        * 0.001;
do_1_2_x = 0        * 0.001;
do_1_2_y = 52.71    * 0.001;
do_1_2_z = 0        * 0.001;

m_1_1 = 3;
m_1_2 = 0.7;

% LINK 2 -> Five elementary cylinder
h_2_1_1 = 54.19     * 0.001;
r_2_1_1 = 58.9      * 0.001;
do_2_1_1_x = -212.5 * 0.001;
do_2_1_1_y = 0      * 0.001;
do_2_1_1_z = -16.26 * 0.001;

h_2_1_2 = 75.81     * 0.001;
r_2_1_2 = 58.9      * 0.001;
do_2_1_2_x = -212.5 * 0.001;
do_2_1_2_y = 0      * 0.001;
do_2_1_2_z = 48.74  * 0.001;

h_2_2 = 307.2       * 0.001;
r_2_2 = 43          * 0.001;
do_2_2_x = 0        * 0.001;
do_2_2_y = 0        * 0.001;
do_2_2_z = 21.64    * 0.001;

h_2_3_1 = 54.19     * 0.001;
r_2_3_1 = 58.9      * 0.001;
do_2_3_1_x = 212.5  * 0.001;
do_2_3_1_y = 0      * 0.001;
do_2_3_1_z = -16.26 * 0.001;

h_2_3_2 = 75.81     * 0.001;
r_2_3_2 = 58.9      * 0.001;
do_2_3_2_x = 212.5  * 0.001;
do_2_3_2_y = 0      * 0.001;
do_2_3_2_z = 48.74  * 0.001;

m_2_1_1 = 3;
m_2_1_2 = 0.7;
m_2_2 = 0.993;
m_2_3_1 = 3;
m_2_3_2 = 0.7;

% LINK 3 -> Five elementary cylinder
h_3_1_1 = 48.46     * 0.001;
r_3_1_1 = 38.4      * 0.001;
do_3_1_1_x = -119.93* 0.001;
do_3_1_1_y = 0      * 0.001;
do_3_1_1_z = 19.27  * 0.001;

h_3_1_2 = 56.54     * 0.001;
r_3_1_2 = 38.4      * 0.001;
do_3_1_2_x = -119.93* 0.001;
do_3_1_2_y = 0      * 0.001;
do_3_1_2_z = -33.23 * 0.001;

h_3_2 = 294.7       * 0.001;
r_3_2 = 37.6        * 0.001;
do_3_2_x = 65.82    * 0.001;
do_3_2_y = 0        * 0.001;
do_3_2_z = -9       * 0.001;

h_3_3_1 = 52.75     * 0.001;
r_3_3_1 = 58.9      * 0.001;
do_3_3_1_x = 272.07 * 0.001;
do_3_3_1_y = 0      * 0.001;
do_3_3_1_z = 17.12  * 0.001;

h_3_3_2 = 37.3      * 0.001;
r_3_3_2 = 58.9      * 0.001;
do_3_3_2_x = 272.07 * 0.001;
do_3_3_2_y = 0      * 0.001;
do_3_3_2_z = -27.9  * 0.001;

m_3_1_1 = 1;
m_3_1_2 = 0.219;
m_3_2 = 0.686;
m_3_3_1 = 0.1;
m_3_3_2 = 0.27;

% LINK 4 -> Two elementary cylinder
h_4_1 = 48.46       * 0.001;
r_4_1 = 38.4        * 0.001;
do_4_1_x = 0        * 0.001;
do_4_1_y = 0        * 0.001;
do_4_1_z = 9.43     * 0.001;

h_4_2 = 56.54       * 0.001;
r_4_2 = 38.4        * 0.001;
do_4_2_x = 0        * 0.001;
do_4_2_y = 0        * 0.001;
do_4_2_z = -43.07   * 0.001;

m_4_1 = 1;
m_4_2 = 0.219;

% LINK 5 -> Two elementary cylinder
h_5_1 = 48.46       * 0.001;
r_5_1 = 38.4        * 0.001;
do_5_1_x = 0        * 0.001;
do_5_1_y = 0        * 0.001;
do_5_1_z = 9.43     * 0.001;

h_5_2 = 56.54       * 0.001;
r_5_2 = 38.4        * 0.001;
do_5_2_x = 0        * 0.001;
do_5_2_y = 0        * 0.001;
do_5_2_z = -43.07   * 0.001;

m_5_1 = 1;
m_5_2 = 0.219;

% LINK 6 -> One elementary cylinder
h_6 = 35            * 0.001;
r_6 = 38.4          * 0.001;

m_6 = 0.1879;


%% Inertia Tensors I_1, ... I_6.
% Assumption: All elementary cylinders are homogeneous with the center
% of mass lying on the geometric center of the cylinder. 
% Links are then assembled with those elementary cylinders with a common mass
% center point. Used: Parallel axes theorem
% If z is rotation axis, then:
% I_zz = 1/2*m*r^2
% I_yy = I_xx = 1/12*m*(3*r^2+h^2)


I_middle(h, r, m) = 1/2*m*r^2;
I_sides(h, r, m) = 1/12*m*(3*r^2+h^2);

I_x(h, r, m) = [I_middle(h, r, m),   0,                     0; 
                0,                  I_sides(h, r, m),       0;
                0,                  0,                      I_sides(h, r, m)];
            
I_y(h, r, m) = [I_sides(h, r, m),   0,                      0; 
                0,                  I_middle(h, r, m),      0;
                0,                  0,                      I_sides(h, r, m)];
            
I_z(h, r, m) = [I_sides(h, r, m),   0,                      0; 
                0,                  I_sides(h, r, m),       0;
                0,                  0,                      I_middle(h, r, m)];

I_off_center(m, do_x, do_y, do_z) =  [m*(do_y^2 + do_z^2),  -m*do_x*do_y,           -m*do_x*do_z; 
                                      -m*do_x*do_y,         m*(do_x^2 + do_z^2),    -m*do_y*do_z;
                                      -m*do_x*do_z,         -m*do_y*do_z,           m*(do_x^2 + do_y^2)];

% Parallel axes theorem for moment of inertia:
% I_xx = I_Cxx + m*(do_y^2 + do_z^2)
% I_yy = I_Cyy + m*(do_x^2 + do_z^2)
% I_zz = I_Czz + m*(do_x^2 + do_y^2)
% Parallel axes theorem for products of inertia:
% I_xy = I_yx = I_Cxy - m*(do_x * do_y)
% I_xz = I_zx = I_Cxz - m*(do_x * do_z)
% I_yz = I_zy = I_Cyz - m*(do_y * do_z)
% where I_Cxy = I_Cxz = I_Cyz = 0 in the case of cylinders.

% LINK 1
I_1_1 = I_y(h_1_1, r_1_1, m_1_1);
I_1_1_off_center = I_off_center(m_1_1, do_1_1_x, do_1_1_y, do_1_1_z);
I_1_2 = I_y(h_1_2, r_1_2, m_1_2);
I_1_2_off_center = I_off_center(m_1_2, do_1_2_x, do_1_2_y, do_1_2_z);
I_1 = I_1_1 + I_1_1_off_center + I_1_2 + I_1_2_off_center;

% LINK 2
I_2_1_1 = I_z(h_2_1_1, r_2_1_1, m_2_1_1)
I_2_1_1_off_center = I_off_center(m_2_1_1, do_2_1_1_x, do_2_1_1_y, do_2_1_1_z)

I_2_1_2 = I_z(h_2_1_2, r_2_1_2, m_2_1_2)
I_2_1_2_off_center = I_off_center(m_2_1_2, do_2_1_2_x, do_2_1_2_y, do_2_1_2_z)

I_2_2 = I_x(h_2_2, r_2_2, m_2_2)
I_2_2_off_center = I_off_center(m_2_2, do_2_2_x, do_2_2_y, do_2_2_z)

I_2_3_1 = I_z(h_2_3_1, r_2_3_1, m_2_3_1)
I_2_3_1_off_center = I_off_center(m_2_3_1, do_2_3_1_x, do_2_3_1_y, do_2_3_1_z)

I_2_3_2 = I_z(h_2_3_2, r_2_3_2, m_2_3_2)
I_2_3_2_off_center = I_off_center(m_2_3_2, do_2_3_2_x, do_2_3_2_y, do_2_3_2_z)

I_2 = I_2_1_1 + I_2_1_1_off_center + I_2_1_2 + I_2_1_2_off_center + ...
      I_2_2 + I_2_2_off_center + ...
      I_2_3_1 + I_2_3_1_off_center  + I_2_3_2 + I_2_3_2_off_center

% LINK 3
I_3_1_1 = I_z(h_3_1_1, r_3_1_1, m_3_1_1);
I_3_1_1_off_center = I_off_center(m_3_1_1, do_3_1_1_x, do_3_1_1_y, do_3_1_1_z);

I_3_1_2 = I_z(h_3_1_2, r_3_1_2, m_3_1_2);
I_3_1_2_off_center = I_off_center(m_3_1_2, do_3_1_2_x, do_3_1_2_y, do_3_1_2_z);

I_3_2 = I_x(h_3_2, r_3_2, m_3_2);
I_3_2_off_center = I_off_center(m_3_2, do_3_2_x, do_3_2_y, do_3_2_z);

I_3_3_1 = I_z(h_3_3_1, r_3_3_1, m_3_3_1);
I_3_3_1_off_center = I_off_center(m_3_3_1, do_3_3_1_x, do_3_3_1_y, do_3_3_1_z);

I_3_3_2 = I_z(h_3_3_2, r_3_3_2, m_3_3_2);
I_3_3_2_off_center = I_off_center(m_3_3_2, do_3_3_2_x, do_3_3_2_y, do_3_3_2_z);

I_3 = I_3_1_1 + I_3_1_1_off_center + I_3_1_2 + I_3_1_2_off_center + ...
      I_3_2 + I_3_2_off_center + ...
      I_3_3_1 + I_3_3_1_off_center  + I_3_3_2 + I_3_3_2_off_center;

% LINK 4
I_4_1 = I_z(h_4_1, r_4_1, m_4_1);
I_4_1_off_center = I_off_center(m_4_1, do_4_1_x, do_4_1_y, do_4_1_z);
I_4_2 = I_z(h_4_2, r_4_2, m_4_2);
I_4_2_off_center = I_off_center(m_4_2, do_4_2_x, do_4_2_y, do_4_2_z);
I_4 = I_4_1 + I_4_1_off_center + I_4_2 + I_4_2_off_center;

% LINK 5
I_5_1 = I_z(h_5_1, r_5_1, m_5_1);
I_5_1_off_center = I_off_center(m_5_1, do_5_1_x, do_5_1_y, do_5_1_z);
I_5_2 = I_z(h_5_2, r_5_2, m_5_2);
I_5_2_off_center = I_off_center(m_5_2, do_5_2_x, do_5_2_y, do_5_2_z);
I_5 = I_5_1 + I_5_1_off_center + I_5_2 + I_5_2_off_center;

% LINK 6
I_6 = I_z(h_6, r_6, m_6);

%% Convert all matrices from symbolic to numeric.
I_1 = double(I_1);
I_2 = double(I_2);
I_3 = double(I_3);
I_4 = double(I_4);
I_5 = double(I_5);
I_6 = double(I_6);
