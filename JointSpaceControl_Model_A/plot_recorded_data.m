%% PLOT_RECORDED_DATA, load and plot the measurement data from the UR5.

% mat_folder_name = 'RecordedUR5Data/Movement_No1/mat_files/';
% mat_folder_name = 'RecordedUR5Data/Movement_No2/mat_files/';
mat_folder_name = 'RecordedUR5Data/Movement_No3_Acc/mat_files/';

% data_names = {'force_sensor', 'i_actual', 'i_target', 'm_target', ...
%               'q_actual', 'q_target', 'qd_actual', 'qd_target', ...
%               'qdd_target', 'tcp_force', 'tcp_speed', 'tool_acc', ...
%               'tool_vector'};

% -------------------------------------------------------------------------
% ------ If used with accelerometer data (and not force sensor data) ------
% -------------------------------------------------------------------------
data_names = {'i_actual', 'i_target', 'm_target', ...
              'q_actual', 'q_target', 'qd_actual', 'qd_target', ...
              'qdd_target', 'tcp_force', 'tcp_speed', 'tool_acc', ...
              'tool_vector', 'acceleration'};

%% Load and plot the data.
for i=1:length(data_names)
    load([mat_folder_name, data_names{i}])
    figure
    eval(['plot(', data_names{i}, '.time, ', data_names{i}, '.signals.values)'])
    title(data_names{i})
end

clear('data_names', 'mat_folder_name','i')
