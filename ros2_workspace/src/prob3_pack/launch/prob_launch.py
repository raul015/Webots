import os
import pathlib
import launch
from launch_ros.actions import Node
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from webots_ros2_driver.webots_launcher import WebotsLauncher, Ros2SupervisorLauncher
# from webots_ros2_driver.utils import get_wsl_ip_address, is_wsl

#Import per settare la porta
def generate_launch_description():
    package_dir = get_package_share_directory('prob3_pack')
    robot_description = pathlib.Path(os.path.join(package_dir, 'resource', 'my_robot.urdf')).read_text()

    webots = WebotsLauncher(
        world=os.path.join(package_dir, 'worlds', 'p-rob3.wbt')
    )

    ros2_supervisor = Ros2SupervisorLauncher()
    # controller_url = 'tcp://' + get_wsl_ip_address() + ':1234/' if is_wsl() else ''


    prob3_driver = Node(
        package='webots_ros2_driver',
        executable='driver',
        output='screen',
        additional_env={'WEBOTS_CONTROLLER_URL':'P-Rob3'},
        parameters=[
            {'robot_description': robot_description},
        ]
    )
    #      above...  additional_env={'WEBOTS_CONTROLLER_URL': controller_url + 'my_robot'},

    

    return LaunchDescription([
        webots,
        prob3_driver,
        ros2_supervisor,
        launch.actions.RegisterEventHandler(
            event_handler=launch.event_handlers.OnProcessExit(
                target_action=webots,
                on_exit=[launch.actions.EmitEvent(event=launch.events.Shutdown())],
            )
        )
    ])