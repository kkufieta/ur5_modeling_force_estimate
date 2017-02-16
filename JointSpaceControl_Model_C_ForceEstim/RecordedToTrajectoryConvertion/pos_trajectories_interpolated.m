close all
%% Load recorded "trajectory", q_target, qd_target, qdd_target
% time_step = 200;
% data_folder_name = 'Pos_Trajectories/200_ms_interpolation/';

% time_step = 80;
% data_folder_name = 'Pos_Trajectories/80_ms_interpolation/';
% 
% time_step = 40;
% data_folder_name = 'Pos_Trajectories/40_ms_interpolation/';
% 
% time_step = 20;
% data_folder_name = 'Pos_Trajectories/20_ms_interpolation/';
% 
time_step = 8;
data_folder_name = 'Pos_Trajectories/8_ms_interpolation/';

mat_folder_name = strcat(data_folder_name, 'mat_files/');
load(strcat(mat_folder_name, 'q_target.mat'))

%% Interpolate a trajectory
% Interpolate a trajectory, i.e. q_target, qd_target and qdd_target and
% split it into points for every 8 ms (instead of 8 ms, 24 ms, 8 ms, ...)

time_original = q_target.time;
values_original = q_target.signals.values;
time_new = q_target.time(1):time_step/1000:q_target.time(end);

values_new = interp1(time_original, values_original, time_new);

figure
plot(time_original, values_original, 'o', time_new, values_new, '*')

%% Write commands into a command.txt file
% Format example: movej([1.265632, -2.135026, -1.947016, -0.376635, -2.541986, -2.736781])

fileID = fopen(strcat(data_folder_name, 'PlannedTrajectories/commands_time_based.txt'),'w');
formatSpec1 = 'movej([%.6f, %.6f, %.6f, %.6f, %.6f, %.6f],a=4, v=0.75, t=%.6f)\n';
% fprintf(fileID, formatSpec1, values_new(:,1), values_new(:,2), values_new(:,3), ...
%     values_new(:,4), values_new(:,5), values_new(:,6))
size_values_new = size(values_new);
for i=1:size_values_new(1)
    fprintf(fileID, formatSpec1, values_new(i,:), time_step/1000);
end
fclose(fileID);

fileID = fopen(strcat(data_folder_name, 'PlannedTrajectories/commands_acc_based.txt'),'w');
formatSpec1 = 'movej([%.6f, %.6f, %.6f, %.6f, %.6f, %.6f],a=25, v=3.2)\n';
for i=1:size_values_new(1)
    fprintf(fileID, formatSpec1, values_new(i,:));
end
fclose(fileID);

fileID = fopen(strcat(data_folder_name, 'PlannedTrajectories/commands.txt'),'w');
formatSpec1 = 'movej([%.6f, %.6f, %.6f, %.6f, %.6f, %.6f])\n';
for i=1:size_values_new(1)
    fprintf(fileID, formatSpec1, values_new(i,:));
end
fclose(fileID);

fileID = fopen(strcat(data_folder_name, 'PlannedTrajectories/commands_with_blend.txt'),'w');
formatSpec1 = 'movej([%.6f, %.6f, %.6f, %.6f, %.6f, %.6f],a=4, v=0.75, t=%.6f, r=0.01)\n';
for i=1:size_values_new(1)
    fprintf(fileID, formatSpec1, values_new(i,:), time_step/1000);
end
fclose(fileID);