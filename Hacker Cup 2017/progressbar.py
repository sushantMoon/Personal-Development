import math

def main():
	tests = raw_input()
	for i in range(int(tests)):
		case = raw_input()
		case = [float(x) for x in case.split(" ")]
		percent = case[0]
		x = case[1]
		y = case[2]
		# print type(percent),type(x),type(y)
		# distance of the point
		distance = math.hypot(50 - x, 50 - y)
		# angle made by the progress bar
		percentTheta = float((percent * 360)/100)
		# print "percent :",percent,"percentAngle : ",percentTheta,"x,y :",x,y,"distance :",distance
		# if point is outside the radius
		if distance > 50 :
			print "Case #"+str(i+1)+": white"
		elif percentTheta == 0:
			print "Case #"+str(i+1)+": white"
		else:
			# now if the point is inside the limit of the radius
			# bringing center to 50,50
			x = x - 50
			y = y - 50
			
			# For first quadrant , angel made by x,y points
			if x >= 0 and y >= 0 :
				# print "first quad"
				angle = 0.0
				if x == 0 and y == 0:
					angle = 0.0
				elif y == 0 and x != 0:
					angle = 90.0
				elif y!= 0 and x == 0:
					angle = 0.0
				else :
					angle = math.degrees(math.atan(float(x/y)))
				# print "percent :",percent,"percentAngle : ",percentTheta,"x,y :",x,y,"distance :",distance,"angle :",angle
				# print "angle :",angle
				if angle == 0 and percentTheta == 0 :
					print "Case #"+str(i+1)+": white"
				elif angle > percentTheta:
					print "Case #"+str(i+1)+": white"
				else :
					print "Case #"+str(i+1)+": black"
			elif x >= 0 and y < 0 :
				# print "second quad"
				angle = 90.0
				if x == 0 :
					angle = 180.0
				else:
					angle = math.degrees(math.atan(float(-1*y/x))) + 90.0
				# print "angle :",angle
				if angle > percentTheta:
					print "Case #"+str(i+1)+": white"
				else :
					print "Case #"+str(i+1)+": black"
			elif x < 0 and y <= 0 :
				# print "third quad"
				angle = 180.0
				if y == 0 :
					angle = 270.0
				else:
					angle = math.degrees(math.atan(float((-1*x)/(-1*y)))) + 180.0
				# print "angle :",angle
				if angle > percentTheta:
					print "Case #"+str(i+1)+": white"
				else :
					print "Case #"+str(i+1)+": black"
			elif x < 0 and y > 0 :
				# print "fourth quad"
				angle = 270.0
				angle = math.degrees(math.atan(float(y/(-1*x)))) + 270.0
				# print "angle :",angle
				if angle > percentTheta:
					print "Case #"+str(i+1)+": white"
				else :
					print "Case #"+str(i+1)+": black"
			else:
				pass


main()