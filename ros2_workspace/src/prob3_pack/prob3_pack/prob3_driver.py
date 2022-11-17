import rclpy
import math
from std_msgs.msg import Float32


class MyRobotDriver:
    def init(self, webots_node, properties):

        # # istanza robot -> nodo di webots 
        self.__robot = webots_node.robot
        self.__timestep = int (self.__robot.getBasicTimeStep())
        
        
        # motori 
        self.__motore_1  = self.__robot.getDevice('motor 1')
        self.__motore_2  = self.__robot.getDevice('motor 2')
        self.__motore_3  = self.__robot.getDevice('motor 3')
        self.__motore_4  = self.__robot.getDevice('motor 4')
        self.__motore_5  = self.__robot.getDevice('motor 5')
        self.__motore_6  = self.__robot.getDevice('motor 6')
        self.__motore_pdx  = self.__robot.getDevice('motor 7')
        self.__motore_psx  = self.__robot.getDevice('motor 7 left')


        # # set delle posizioni iniziali
        # self.__motore_1.setPosition(float('inf'))
        # self.__motore_1.setVelocity(0)
        self.__motore_1.setPosition(float('inf'))
        self.__motore_1.setVelocity(0)
        
        self.__motore_2.setPosition(float('inf'))
        self.__motore_2.setVelocity(0)
        
        self.__motore_3.setPosition(float('inf'))
        self.__motore_3.setVelocity(0)
        
        self.__motore_4.setPosition(float('inf'))
        self.__motore_4.setVelocity(0)
        
        self.__motore_5.setPosition(float('inf'))
        self.__motore_5.setVelocity(0)
        
        self.__motore_6.setPosition(float('inf'))
        self.__motore_6.setVelocity(0)
        
        self.__motore_pdx.setPosition(float('inf'))
        self.__motore_pdx.setVelocity(0)
    
        self.__motore_psx.setPosition(float('inf'))
        self.__motore_psx.setVelocity(0)
        
        #Stato
        
        
        self.__motore1_position = Float32()
        self.__motore1_velocity = Float32()
        
        self.__motore2_position = Float32()
        self.__motore2_velocity = Float32()
        
        self.__motore3_position = Float32()
        self.__motore3_velocity = Float32()
        
        self.__motore4_position = Float32()
        self.__motore4_velocity = Float32()
        
        self.__motore5_position = Float32()
        self.__motore5_velocity = Float32()
        
        self.__motore6_position = Float32()
        self.__motore6_velocity = Float32()

        self.__motorepdx_position = Float32()
        self.__motorepdx_velocity = Float32()
        
        self.__motorepsx_position = Float32()
        self.__motorepsx_velocity = Float32()
        
        rclpy.init(args=None)
        
        self.__node = rclpy.create_node('prob3_driver')
        self.__node.create_subscription(Float32, 'motore_1_position', self.__motore1_position_callback, 1)
        self.__node.create_subscription(Float32, 'motore_2_position', self.__motore2_position_callback, 1)        
        self.__node.create_subscription(Float32, 'motore_3_position', self.__motore3_position_callback, 1)
        self.__node.create_subscription(Float32, 'motore_4_position', self.__motore4_position_callback, 1)
        self.__node.create_subscription(Float32, 'motore_5_position', self.__motore5_position_callback, 1)
        self.__node.create_subscription(Float32, 'motore_6_position', self.__motore6_position_callback, 1)
        self.__node.create_subscription(Float32, 'motore_pdx_position', self.__motorepdx_position_callback, 1)
        self.__node.create_subscription(Float32, 'motore_psx_position', self.__motorepsx_position_callback, 1)

        
        self.__node.create_subscription(Float32, 'motore_1_velocity', self.__motore1_velocity_callback, 1)
        self.__node.create_subscription(Float32, 'motore_2_velocity', self.__motore2_velocity_callback, 1)
        self.__node.create_subscription(Float32, 'motore_3_velocity', self.__motore3_velocity_callback, 1)
        self.__node.create_subscription(Float32, 'motore_4_velocity', self.__motore4_velocity_callback, 1)
        self.__node.create_subscription(Float32, 'motore_5_velocity', self.__motore5_velocity_callback, 1)
        self.__node.create_subscription(Float32, 'motore_6_velocity', self.__motore6_velocity_callback, 1)
        self.__node.create_subscription(Float32, 'motore_pdx_velocity', self.__motorepdx_velocity_callback, 1)
        self.__node.create_subscription(Float32, 'motore_psx_velocity', self.__motorepsx_velocity_callback, 1)


        # self.publisher_ = self.create_publisher(String, 'topic', 10)

    # def __cmd_vel_callback(self, position):
    #     self._target_position = position
    
    def __motore1_position_callback(self, position):
        self.__motore1_position = position
    def __motore1_velocity_callback(self, velocity):
        self.__motore1_velocity = velocity
        
    def __motore2_position_callback(self, position):
        self.__motore2_position = position
    def __motore2_velocity_callback(self, velocity):
        self.__motore2_velocity = velocity       

    def __motore3_position_callback(self, position):
        self.__motore3_position = position
    def __motore3_velocity_callback(self, velocity):
        self.__motore3_velocity = velocity
        
    def __motore4_position_callback(self, position):
        self.__motore4_position = position
    def __motore4_velocity_callback(self, velocity):
        self.__motore4_velocity = velocity       
        
    def __motore5_position_callback(self, position):
        self.__motore5_position = position
    def __motore5_velocity_callback(self, velocity):
        self.__motore5_velocity = velocity
        
    def __motore6_position_callback(self, position):
        self.__motore6_position = position
    def __motore6_velocity_callback(self, velocity):
        self.__motore6_velocity = velocity    
        
    def __motorepdx_position_callback(self, position):
        self.__motorepdx_position = position
    def __motorepdx_velocity_callback(self, velocity):
        self.__motorepdx_velocity = velocity
        
    def __motorepsx_position_callback(self, position):
        self.__motorepsx_position = position
    def __motorepsx_velocity_callback(self, velocity):
        self.__motorepsx_velocity = velocity          
        
        

    def step(self):
        rclpy.spin_once(self.__node, timeout_sec=0)
        
        self.__motore_1.setPosition(self.__motore1_position.data)
        self.__motore_1.setVelocity(self.__motore1_velocity.data)
        
        self.__motore_2.setPosition(self.__motore2_position.data)
        self.__motore_2.setVelocity(self.__motore2_velocity.data)
        
        self.__motore_3.setPosition(self.__motore3_position.data)
        self.__motore_3.setVelocity(self.__motore3_velocity.data)
        
        self.__motore_4.setPosition(self.__motore4_position.data)
        self.__motore_4.setVelocity(self.__motore4_velocity.data)
        
        self.__motore_5.setPosition(self.__motore5_position.data)
        self.__motore_5.setVelocity(self.__motore5_velocity.data)
        
        self.__motore_6.setPosition(self.__motore6_position.data)
        self.__motore_6.setVelocity(self.__motore6_velocity.data)
        
        self.__motore_pdx.setPosition(self.__motorepdx_position.data)
        self.__motore_pdx.setVelocity(self.__motorepdx_velocity.data)
        
        self.__motore_psx.setPosition(self.__motorepsx_position.data)
        self.__motore_psx.setVelocity(self.__motorepsx_velocity.data)
        
        
        # posizione = self._target_position.displacements #float64
        # velocita = self._target_position.velocities #float64
        # self.__motore_1.setPosition(posizione)
        # self.__motore_1.setVelocity(velocita)
        
        # msg = String()
        # msg.data = 'Hello World: %d' % self.i
        # self.publisher_.publish(msg)
        # self.get_logger().info('Publishing: "%s"' % msg.data)
        # self.i += 1

        