/*
 See LICENSE folder for this sample’s licensing information.
 
 Abstract:
 A view showing a list of landmarks.
 */

import SwiftUI

struct LandmarkList: View {
    var body: some View {
        NavigationView {
        List(landmarkData) { landmark in
            
            NavigationLink(destination: LandmarkDetail(landmark: landmark))
            {
                LandmarkRow(landmark: landmark)
            }.buttonStyle(.plain)
        }
        .navigationBarTitle(Text("Landmarks"))
        .listStyle(.plain)
        
    }
    
}


}

struct LandmarkList_Previews: PreviewProvider {
    static var previews: some View {
        ForEach(["iPhone SE", "iPhone XS Max"], id: \.self) { deviceName in
            LandmarkList()
                .previewDevice(PreviewDevice(rawValue: deviceName))
                .previewDisplayName(deviceName)
        }
    }
}
