kernel WipeKernel : ImageComputationKernel<eComponentWise>
{
  Image<eRead, eAccessPoint, eEdgeClamped> above;  //image to show above the line
  Image<eRead, eAccessPoint, eEdgeClamped> below;  //image to show below the line
  Image<eWrite> dst;  //the output image

  param:
   float2 origin;
   float angle;

  local:
   float2 vec;

  //In define(), parameters can be given labels and default values.
  void define() {
    defineParam(origin, "Origin", float2(50.0f, 50.0f));
    defineParam(angle, "Angle", 45.0f);
  }

  //The init() function is run before any calls to process().
  void init() {
    vec.x = cos(angle * PI / 180.0f);
    vec.y = sin(angle * PI / 180.0f);
  }

  //The process function is run at every pixel to produce the output.
  void process(int2 pos) {
    float2 posVec;
    posVec.x = pos.x - origin.x;
    posVec.y = pos.y - origin.y;

    //Z value of cross product
    float val = vec.x * posVec.y - vec.y * posVec.x;
    if(val > 0.0f) {
      dst() = above();
    }
    else {
      dst() = below();
    }
  }
};
