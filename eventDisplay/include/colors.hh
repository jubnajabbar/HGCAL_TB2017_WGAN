#include "G4Colour.hh"
#include "DetectorConstruction.hh"
#include <iostream>

//http://ultrahigh.org/2007/08/making-pretty-root-color-palettes/
std::vector<float> HGCAL_energies = {0.0, 0.5, 1.5, 5.0, 50, 120, 500};            //must start at 0 and must have at least two entries
std::vector<float> HGCAL_red = {1.00, 0.0, 0.00, 0.00, 0.87, 1.00, 0.51};
std::vector<float> HGCAL_green = {1.00, 0.0, 0.00, 0.81, 1.00, 0.20, 0.00};
std::vector<float> HGCAL_blue = {1.00, 0.0, 0.51, 1.00, 0.12, 0.00, 0.00};


std::vector<float> AHCAL_energies = {0.0, 0.5, 1.5, 5.0, 50, 120, 500};            //must start at 0 and must have at least two entries
std::vector<float> AHCAL_red = {1.00, 0.0, 0.00, 0.00, 0.87, 1.00, 0.51};
std::vector<float> AHCAL_green = {1.00, 0.0, 0.00, 0.81, 1.00, 0.20, 0.00};
std::vector<float> AHCAL_blue = {1.00, 0.0, 0.51, 1.00, 0.12, 0.00, 0.00};

void setHGCALHitColor (VisHit* hit) {
      float hit_energy = hit->energy;
      unsigned short upper_index = HGCAL_energies.size()-1;
      unsigned short lower_index = HGCAL_energies.size()-1;
      
      for (unsigned short i=0; i<HGCAL_energies.size(); i++) {
            if (hit_energy<HGCAL_energies[i]) {
                  upper_index = i;
                  lower_index = i-1;
                  break;
            }
      }

      hit->red = upper_index!=lower_index ? (HGCAL_red[upper_index]-HGCAL_red[lower_index])/(HGCAL_energies[upper_index]-HGCAL_energies[lower_index]) * (hit_energy-HGCAL_energies[lower_index])+HGCAL_red[lower_index] : HGCAL_red[lower_index];
      hit->green = upper_index!=lower_index ? (HGCAL_green[upper_index]-HGCAL_green[lower_index])/(HGCAL_energies[upper_index]-HGCAL_energies[lower_index]) * (hit_energy-HGCAL_energies[lower_index])+HGCAL_green[lower_index] : HGCAL_green[lower_index];
      hit->blue = upper_index!=lower_index ? (HGCAL_blue[upper_index]-HGCAL_blue[lower_index])/(HGCAL_energies[upper_index]-HGCAL_energies[lower_index]) * (hit_energy-HGCAL_energies[lower_index])+HGCAL_blue[lower_index] : HGCAL_blue[lower_index];

}

void setAHCALHitColor (VisHit* hit) {
      float hit_energy = hit->energy;
      unsigned short upper_index = AHCAL_energies.size()-1;
      unsigned short lower_index = AHCAL_energies.size()-1;
      
      for (size_t i=0; i<AHCAL_energies.size(); i++) {
            if (hit_energy<AHCAL_energies[i]) {
                  upper_index = i;
                  lower_index = i-1;
                  break;
            }
      }

      hit->red = upper_index!=lower_index ? (AHCAL_red[upper_index]-AHCAL_red[lower_index])/(AHCAL_energies[upper_index]-AHCAL_energies[lower_index]) * (hit_energy-AHCAL_energies[lower_index])+AHCAL_red[lower_index] : AHCAL_red[lower_index];
      hit->green = upper_index!=lower_index ? (AHCAL_green[upper_index]-AHCAL_green[lower_index])/(AHCAL_energies[upper_index]-AHCAL_energies[lower_index]) * (hit_energy-AHCAL_energies[lower_index])+AHCAL_green[lower_index] : AHCAL_green[lower_index];
      hit->blue = upper_index!=lower_index ? (AHCAL_blue[upper_index]-AHCAL_blue[lower_index])/(AHCAL_energies[upper_index]-AHCAL_energies[lower_index]) * (hit_energy-AHCAL_energies[lower_index])+AHCAL_blue[lower_index] : AHCAL_blue[lower_index];
}