%% Interpolate a trajectory
% Interpolate a trajectory, i.e. q_target, qd_target and qdd_target and
% split it into points for every 8 ms (instead of 8 ms, 24 ms, 8 ms, ...)

time_original = q_target.time;
values_original = q_target.signals.values;
time_new = q_target.time(1):0.008:q_target.time(end);

values_new = interp1(time_original, values_original, time_new);

figure
plot(time_original, values_original, 'o', time_new, values_new, '*')

%% Write commands into a command.txt file
% Format example: movej([1.265632, -2.135026, -1.947016, -0.376635, -2.541986, -2.736781])

fileID = fopen('PlannedTrajectories/commandos_time_based.txt','w');
formatSpec1 = 'movej([%.6f, %.6f, %.6f, %.6f, %.6f, %.6f],a=4, v=0.75, t=0.008)\n';
fprintf(fileID, formatSpec1, values_new(:,1)', values_new(:,2)', values_new(:,3)', ...
    values_new(:,4)', values_new(:,5)', values_new(:,6)')
fclose(fileID);

fileID = fopen('PlannedTrajectories/commandos_acc_based.txt','w');
formatSpec1 = 'movej([%.6f, %.6f, %.6f, %.6f, %.6f, %.6f],a=25, v=3.2)\n';
fprintf(fileID, formatSpec1, values_new(:,1)', values_new(:,2)', values_new(:,3)', ...
    values_new(:,4)', values_new(:,5)', values_new(:,6)')
fclose(fileID);

fileID = fopen('PlannedTrajectories/commandos.txt','w');
formatSpec1 = 'movej([%.6f, %.6f, %.6f, %.6f, %.6f, %.6f])\n';
fprintf(fileID, formatSpec1, values_new(:,1)', values_new(:,2)', values_new(:,3)', ...
    values_new(:,4)', values_new(:,5)', values_new(:,6)')
fclose(fileID);