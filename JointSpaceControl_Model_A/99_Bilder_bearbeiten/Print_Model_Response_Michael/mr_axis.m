function handle = mr_axis(axpos,axsize)
% function handle = mr_axes(axpos,axsize, Box);
% Build axes for figures.
% axpos gives position of current axis
% axsize gives size of axis
% Box 'on' or 'off'

Pos = [axpos axsize];

handle = axes('Position',Pos,'Box','on');
%end % function mr_axes
%--------------------------------------------------------------------------