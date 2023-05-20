##
## EPITECH PROJECT, 2023
## Raytracer
## File description:
## Makefile
##

SRC	=	src/main.cpp					\
		src/Utils/StringUtils.cpp		\
		src/Utils/FileUtils.cpp			\
		src/Utils/ConfigParser.cpp		\
		src/Utils/Rgb.cpp				\
		src/Utils/PPMWriter.cpp			\
		src/Math/MathUtils.cpp			\
		src/Math/Vector3D.cpp			\
		src/Math/Point3D.cpp			\
		src/Math/Rectangle3D.cpp		\
		src/Math/Ray3D.cpp				\
		src/Primitives/AShape.cpp		\
		src/Primitives/Sphere.cpp		\
		src/Camera.cpp					\
		src/Raytracer.cpp				\
		src/Light.cpp					\
		src/Primitives/Cone.cpp			\
		src/Primitives/ShapeFactory.cpp	\
		src/Primitives/Cylindre.cpp		\
		src/CameraBuilder.cpp			\
		src/Utils/LightCalculator.cpp	\
		src/Primitives/Rectangle.cpp	\
		src/LightBuilder.cpp			\

NAME	=	raytracer

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	-std=c++20 -g3 -Wall

CPPFLAGS 	= 	-Iinclude/ -Isrc/

CXX	=	g++

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CXX) -o $(NAME) $(OBJ)
	@make clean

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) ./vgcore*

re:	fclean all

.PHONY: all clean fclean re