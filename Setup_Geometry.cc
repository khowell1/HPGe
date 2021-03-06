#include "Setup_Geometry.h"

Double_t Setup_Geometry::PI=3.141592653589793238462;
Double_t Setup_Geometry::dr=0.1;

Setup_Geometry::SetupGeometry() { //default object constructor
  //only creates the ge detector geometry in the first array position  
  cyl_radius=4.11; //cm
  cyl_height=6.53; //cm
  volume_number=0;
  geometrydata[0]={volume_number,cyl_radius,cyl_height};
  // geometrydata[0][0]=volume_number;
  // geometrydata[0][1]=cyl_radius;
  // geometrydata[0][2]=cyl_height;
}

Setup_Geometry::SetupGeometry(Int_t new_volume_number,Double_t new_cyl_radius,Double_t new_cyl_height) {
  //normal object constructor
  cyl_radius=new_cyl_radius;
  cyl_height=new_cyl_height;
  volume_number=new_volume_number;
  geometrydata[new_volume_number]={new_volume_number,new_cyl_radius,new_cyl_height};
  // geometrydata[new_volume_number][0]=new_volume_number;
  // geometrydata[new_volume_number][1]=new_cyl_radius;
  // geometrydata[new_volume_number][2]=new_cyl_height;
}

void SetVolumeNumber(Int_t new_volume_number) {
  volume_number=new_volume_number;
}

Int_t GetVolumeNumber() {
  return volume_number;
}

void Setup_Geometry::SetGeometryData(Double new_geometrydata[]) {
  //for changing the geo data for each volume individually
  geometrydata[new_geometrydata[0]]={new_geometrydata[0],new_geometrydata[1],new_geometrydata[2]};
}

Double_t Setup_Geometry::GetGeometryData(Int_t volume_number) {
  //just prints the geometry data
  cout<<geometrydata[volume_number][0]<<","<<geometrydata[volume_number][1]<<","<<geometrydata[volume_number][2]<<endl;
  return 0;
}

void Setup_Geometry::SetPhotonPosition(Double new_cartposition[]) {
  cartposition[0]=new_cartposition[0];
  cartposition[1]=new_cartposition[1];
  cartposition[2]=new_cartposition[2];
}

Double_t Setup_Geometry::GetPhotonPosition() {
  //just prints the position, do I actually need to return a position?
  cout<<cartposition[0]<<","<<cartposition[1]<<","<<cartposition[2]<<endl;
  return 0;
}

// void Setup_Geometry::PhotonSphCoordChanger(Double_t oldsphposition[],Double_t newsphaddition[]) { //just changing the old spherical array to the new calculated spherical array
//    oldsphposition[0]=newsphaddition[0];
//    oldsphposition[1]=newsphaddition[1];
//    oldsphposition[2]=newsphaddition[2];
// }

// void PhotonSphCoordUpdater(Double_t oldsphposition[],Double newsphaddition[],Double_t finalsphposition[],Double_t cartposition[],Double_t PI) {
// //switching to cartesian...and adding up the new and old coordinates
//    cartposition[0]=oldsphposition[0]*sin(oldsphposition[1]*180.0/PI)*cos(oldsphposition[2]*180.0*PI)+newsphaddition[0]*sin(newsphaddition[1]*180.0/PI)*cos(newsphaddition[2]*180.0/PI); //cart x
//   cartposition[1]=oldsphposition[0]*sin(oldsphposition[1]*180.0/PI)*sin(oldsphposition[2]*180.0*PI)+newsphaddition[0]*sin(newsphaddition[1]*180.0/PI)*sin(newsphaddition[2]*180.0/PI); //cart y
//   cartposition[2]=oldsphposition[0]*cos(oldsphposition[1]*180.0/PI)+newsphaddition[0]*cos(newsphaddition[1]*180.0/PI); //cart z
//   cout<<"cart: "<<cartposition[0]<<","<<cartposition[1]<<","<<cartposition[2]<<endl;

//   //switching from cartesian to spherical
//   finalsphposition[0]=sqrt(cartposition[0]*cartposition[0]+cartposition[1]*cartposition[1]+cartposition[2]*cartposition[2]); //new spherical radius
//   finalsphposition[1]=TMath::ACos(cartposition[2]/finalsphposition[0]);//theta
//   newarray[2]=TMath::ATan2(cartposition[1],cartposition[0]);//phi
//   cout<<"spherical: "<<finalsphposition[0]<<","<<finalsphposition[1]<<","<<finalsphposition[2]<<endl;
// }

// Double_t ExitGeometryChecker(Double_t finalsphposition[],Double_t exitsphposition,Double_t cyl_radius,Double_t cyl_height) {
//   //to change the new array's spherical coordinates to cylinder:
//   //  cylposition[0]=finalsphposition[0]*sin(finalsphposition[1]*180.0/PI); 
//   //  cylposition[1]=finalsphposition[1];
//   //  cylposition[2]=finalsphposition[0]*cos(finalsphposition[1]*180.0/PI);
//   if (finalsphposition[0]*sin(finalsphposition[1]*180.0/PI)>cyl_radius || finalsphposition[0]*cos(finalsphposition[1]*180.0/PI)>cyl_height) {
//     exitsphposition[0]=finalsphposition[0]-(finalsphposition[0]-cyl_radius);
//     exitsphposition[1]=finalsphposition[1];
//     exitsphposition[2]=finalsphposition[2]-(finalsphposition[2]-cyl_radius);
//     return true; //need to tell master class that the photon exited!
//   }
//   //need to just switch this all to either spherical or cart, prob cart since i can do subtraction and addition in it. the above code doesn't fucking work anyway. can keep using the cyl info for finding boundaries and such, but probably should just stick to two coord systems. 
//   return 0;
// }

// void WhichVolumeChecker(Double_t finalsphposition,Double_t geometrydata[][],Double_t dr) {
//   //will decide which volume the photon is in by increasing r by dr, checking cyl coords
//   Double_t fakesphposition[3]={finalsphposition+dr,finalsphposition[1],finalsphposition[2]};
//   Double_t fakecylposition[3]={fakesphposition[0]*sin(fakesphposition[1]*180.0/PI),fakesphposition[1],fakesphposition[0]*cos(fakesphposition[1]*180.0/PI)};
//   for (int n=0;n<=(sizeof(geometrydata)/sizeof(*geometrydata));n++) {
//     if (fakecylposition[0]<geometrydata[n][1]) {
//       volume_number=n;
//       break;
//     }
//     else if (fakecylposition[2]<geometrydata[n][2]){
//       volume_number=n;
//       break;
//     }
//   }
// }

//the sine functions take radians!
