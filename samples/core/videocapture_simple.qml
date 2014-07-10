import 'lcvcore' 1.0

Rectangle{
    
    property string videoPath : codeDocument.path + '/../_videos/amherst-11_2754_3754.avi'
    
    VideoCapture{
        file : parent.videoPath
        id : videoArea
        loop : true
        fps : 100
    }
    
    
    
}