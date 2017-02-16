%% LOAD_RECORDED_DATA, load and plot the measurement data from the UR5.

% mat_folder_name = 'RecordedUR5Data/Movement_No1/mat_files/';
% mat_folder_name = 'RecordedUR5Data/Movement_No2/mat_files/';
% mat_folder_name = 'RecordedUR5Data/Movement_No3_Acc/mat_files/';

mat_folder_name = 'RecordedUR5Data/Movement_No5_Acc_slow_no_disturbance/mat_files/'; % Has Singularities  
% mat_folder_name = 'RecordedUR5Data/Movement_No5_Acc_slow_w_disturbance/mat_files/'; % Has Singularities  
% mat_folder_name = 'RecordedUR5Data/Movement_No6_Acc_slow_Verify_Model/mat_files/'; % Has Singularities  
% mat_folder_name = 'RecordedUR5Data/Movement_No7_Acc_slow_Verify_Model_short/mat_files/'; % Has Singularities  
% mat_folder_name = 'RecordedUR5Data/Movement_No7_Acc_slow_Verify_Model_short_with_disturbance/mat_files/'; % Has Singularities  

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

%% Simulation end time
load([mat_folder_name, 'q_target'])
sim_end = q_target.time(end);

%% Load and plot the data.
for i=1:length(data_names)
    load([mat_folder_name, data_names{i}])
    temp_sim_end = eval([data_names{i},'.time(end)']);
    if temp_sim_end < sim_end
        sim_end = temp_sim_end;
    end
end

clear('data_names', 'mat_folder_name','i')
