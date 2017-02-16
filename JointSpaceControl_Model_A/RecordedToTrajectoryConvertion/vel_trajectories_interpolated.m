% close all
%% Load recorded "trajectory", q_target, qd_target, qdd_target
time_step = 240;
data_folder_name = 'Vel_Trajectories/240_ms_interpolation/';

% time_step = 80;
% data_folder_name = 'Vel_Trajectories/80_ms_interpolation/';
% 
% time_step = 40;
% data_folder_name = 'Vel_Trajectories/40_ms_interpolation/';
% 
% time_step = 24;
% data_folder_name = 'Vel_Trajectories/24_ms_interpolation/';
% 
% time_step = 8;
% data_folder_name = 'Vel_Trajectories/8_ms_interpolation/';

mat_folder_name = strcat(data_folder_name, 'mat_files/');
load(strcat(mat_folder_name, 'q_target.mat'))
load(strcat(mat_folder_name, 'qd_target.mat'))
load(strcat(mat_folder_name, 'qdd_target.mat'))

%% Interpolate a trajectory
% Interpolate a trajectory, i.e. q_target, qd_target and qdd_target and
% split it into points for every 8 ms (instead of 8 ms, 24 ms, 8 ms, ...)

time_original = qd_target.time;
values_original = qd_target.signals.values;
time_new = qd_target.time(1):time_step/1000:qd_target.time(end);

values_new = interp1(time_original, values_original, time_new);

figure
plot(time_original, values_original, 'o', time_new, values_new, '*')

%% Interpolate the acceleration
time_original_acc = qdd_target.time;
values_original_acc = qdd_target.signals.values;
time_new_acc = qdd_target.time(1):time_step/1000:qdd_target.time(end);

values_new_acc = interp1(time_original_acc, values_original_acc, time_new_acc);

figure
plot(time_original_acc, values_original_acc, '-', time_new_acc, values_new_acc, '*')

%% Get the first position and save it in a file
first_position = q_target.signals.values(1,:);
fileID = fopen(strcat(data_folder_name, 'PlannedTrajectories/first_position.txt'),'w');
formatSpec1 = 'movej([%.6f, %.6f, %.6f, %.6f, %.6f, %.6f],a=3, v=0.75, t=0)\n';
fprintf(fileID, formatSpec1, first_position);
fclose(fileID);

%% Write commands into a command.txt file
% Format example: movej([1.265632, -2.135026, -1.947016, -0.376635, -2.541986, -2.736781])

fileID = fopen(strcat(data_folder_name, 'PlannedTrajectories/vel_commands.txt'),'w');
formatSpec1 = 'speedj([%.6f, %.6f, %.6f, %.6f, %.6f, %.6f],a=%.6f, t_min = %.6f)\n';
size_values_new = size(values_new);
for i=1:size_values_new(1)
    fprintf(fileID, formatSpec1, values_new(i,:), max(values_new_acc(i,:)), time_step/1000);
end
fclose(fileID);