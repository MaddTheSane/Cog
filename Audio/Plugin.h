//Plugins! HOORAY!

@protocol CogSource <NSObject>
+ (NSArray *)schemes; //http, file, etc

- (NSURL *)url;
- (NSString *)mimeType;

- (BOOL)open:(NSURL *)url;
- (BOOL)seekable;
- (BOOL)seek:(long)position whence:(int)whence;
- (long)tell;
- (long)read:(void *)buffer amount:(long)amount; //reads UP TO amount, returns amount read.
- (void)close;
- (void)dealloc;
@end

@protocol CogContainer <NSObject> 
+ (NSArray<NSString*> *)fileTypes; //mp3, ogg, etc
+ (NSArray<NSString*> *)mimeTypes;
+ (float)priority;

+ (NSArray<NSURL*> *)urlsForContainerURL:(NSURL *)url;
@end

@protocol CogDecoder <NSObject> 
@required
+ (NSArray<NSString*> *)mimeTypes;
+ (NSArray<NSString*> *)fileTypes; //mp3, ogg, etc
+ (float)priority; // should be 0.0 ... 1.0, higher means you get selected first, should default to 1.0 unless you know a reason why any of your extensions may behave badly, ie. greedily taking over some file type extension without performing any header validation on it

//For KVO
//- (void)setProperties:(NSDictionary *)p;
- (NSDictionary *)properties;

- (int)readAudio:(void *)buffer frames:(UInt32)frames;

- (BOOL)open:(id<CogSource>)source;
- (long)seek:(long)frame;
- (void)close;

@optional
- (BOOL)setTrack:(NSURL *)track;

//These are in NSObject, so as long as you are a subclass of that, you are ok.
- (void)addObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(void *)context;
- (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath;
@end

@protocol CogMetadataReader <NSObject>
+ (NSArray<NSString*> *)fileTypes;
+ (NSArray<NSString*> *)mimeTypes;
+ (float)priority;
+ (NSDictionary<NSString*,id> *)metadataForURL:(NSURL *)url;
@end

@protocol CogMetadataWriter <NSObject>
//+ (NSArray *)fileTypes;
//+ (NSArray *)mimeTypes;
+ (int)putMetadataInURL:(NSURL *)url tagData:(NSDictionary *)tagData;
@end

@protocol CogPropertiesReader <NSObject>
+ (NSArray<NSString*> *)fileTypes;
+ (NSArray<NSString*> *)mimeTypes;
+ (float)priority;
+ (NSDictionary *)propertiesForSource:(id<CogSource>)source;
@end

@protocol CogPluginController <NSObject>
+ (id<CogPluginController>)sharedPluginController;

- (NSDictionary *)sources;
- (NSDictionary *)containers;
- (NSDictionary *)metadataReaders;

- (NSDictionary *)propertiesReadersByExtension;
- (NSDictionary *)propertiesReadersByMimeType;

- (NSDictionary *)decodersByExtension;
- (NSDictionary *)decodersByMimeType;

- (id<CogSource>) audioSourceForURL:(NSURL *)url;
- (NSArray *) urlsForContainerURL:(NSURL *)url;
- (NSDictionary *) metadataForURL:(NSURL *)url;
- (NSDictionary *) propertiesForURL:(NSURL *)url;
- (id<CogDecoder>) audioDecoderForSource:(id<CogSource>)source;

- (int) putMetadataInURL:(NSURL *)url;
@end



